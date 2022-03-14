//
//  ViewController.swift
//  BeepExpire
//
//  Created by Lucio Cocorullo on 28/02/22.
//

import ScanditBarcodeCapture
import Foundation
import AVFoundation

extension DataCaptureContext {
    
    private static let licenseKey = "AbUhgBWxNMKiM+J7jDVH+AYiJm9gMkBSsXvmZ8Nfor/zULenhnq5BHtx67eOck+kM2jq+41GS7hmH1LlPndW5WcavJtjUWR75QRFZW1vsSsfZ78PdnhvKtIMPOCRYhFG2k2Y8zcRPjZzKdMQ5g7WA58Ef2vHDsBJwaD5Vw5uzYxWDHMTcK4W+4cfsyH5VhEzku9Vcs/lPfYoHJKtKP5qEmJUW2/5pvslW4C6L4+rGoEI74KBLw7EvVGgFUTLCeTRfZM9151AHCIUfHXN0gFjATbxwcUkdaycEMOzhtortffMMD10EcJspOfxu+Badgze7vjwroIkEuyS12m88Sl6lYSoMLQmavOoEdVoF7Qvl3wEXPgDutK5IAdQ9bMYyjPmS4CXMhxPcwNVZe2+KYwshyhwNYtxgmm8rGO+BVR2QlN9/XDKDmBFfYlfOg4t61KxefxVYh1RDdebpeGZVRdt38dgfkJsU8ZGzFUvvnTmy42SxwU+14pFRIJhPNuaGoRG258TZvk6zdAgrGeUlZ7oajm0u+jfASEVBuzlih4hO/ZPKJpgdUO8J0EsUmpWyz6OSZVgqKFJq5bxfsuyvoipdylzCwIagADr1y2k71XBUQ+GOu74pPryOJh0Mt26Tu7HkqCzhXlS/4Csq6MBIES2pG1iVIDmNwlgfIXBsCNkL8mONkLV5eA2S5XGmGy/JNRUUqEioUJGntfjn/50X8/PB87Y/eUFvSUw4pp/pZo0Try6Oq6GJxjx/n0qa8mcWlO5XV75XzoRlgzQQOCcJ6el4zcbL7GsXl2jnlaJz0c1AaIoUov9nz26Wq3/D/9Jtmihbd8dw3U="

    // Get a licensed DataCaptureContext.
    static var licensed: DataCaptureContext {
        return DataCaptureContext(licenseKey: licenseKey)
    }
    
}

class ViewController: UIViewController {

    private var context: DataCaptureContext!
    private var camera: Camera?
    private var barcodeCapture: BarcodeCapture!
    private var captureView: DataCaptureView!
    private var overlay: BarcodeCaptureOverlay!

    override func viewDidLoad() {
        
        super.viewDidLoad()
        setupRecognition()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)

        // Switch camera on to start streaming frames. The camera is started asynchronously and will take some time to
        // completely turn on. To be notified when the camera is completely on, pass non nil block as completion to
        // camera?.switch(toDesiredState:completionHandler:)
        barcodeCapture.isEnabled = true
        camera?.switch(toDesiredState: .on)
    }

    override func viewDidDisappear(_ animated: Bool) {
        super.viewDidDisappear(animated)

        // Switch camera off to stop streaming frames. The camera is stopped asynchronously and will take some time to
        // completely turn off. Until it is completely stopped, it is still possible to receive further results, hence
        // it's a good idea to first disable barcode capture as well.
        // To be notified when the camera is completely stopped, pass a non nil block as completion to
        // camera?.switch(toDesiredState:completionHandler:)
        barcodeCapture.isEnabled = false
        camera?.switch(toDesiredState: .off)
    }

    func setupRecognition() {
        // Create data capture context using your license key.
        context = DataCaptureContext.licensed

        // Use the world-facing (back) camera and set it as the frame source of the context. The camera is off by
        // default and must be turned on to start streaming frames to the data capture context for recognition.
        // See viewWillAppear and viewDidDisappear above.
        camera = Camera.default
        context.setFrameSource(camera, completionHandler: nil)

        // Use the recommended camera settings for the BarcodeCapture mode.
        let recommendedCameraSettings = BarcodeCapture.recommendedCameraSettings
        camera?.apply(recommendedCameraSettings)
       

        // The barcode capturing process is configured through barcode capture settings
        // and are then applied to the barcode capture instance that manages barcode recognition.
        let settings = BarcodeCaptureSettings()

        // The settings instance initially has all types of barcodes (symbologies) disabled. For the purpose of this
        // sample we enable a very generous set of symbologies. In your own app ensure that you only enable the
        // symbologies that your app requires as every additional enabled symbology has an impact on processing times.
        settings.set(symbology: .dataMatrix, enabled: true)
        settings.set(symbology: .code128, enabled: true)
        settings.set(symbology: .interleavedTwoOfFive, enabled: true)

        // Some linear/1d barcode symbologies allow you to encode variable-length data. By default, the Scandit
        // Data Capture SDK only scans barcodes in a certain length range. If your application requires scanning of one
        // of these symbologies, and the length is falling outside the default range, you may need to adjust the "active
        // symbol counts" for this symbology. This is shown in the following few lines of code for one of the
        // variable-length symbologies.
        let symbologySettings = settings.settings(for: .code39)
        symbologySettings.activeSymbolCounts = Set(7...20) as Set<NSNumber>

        startTutorial()
        
        // Create new barcode capture mode with the settings from above.
        barcodeCapture = BarcodeCapture(context: context, settings: settings)

        // Register self as a listener to get informed whenever a new barcode got recognized.
        barcodeCapture.addListener(self)
        barcodeCapture.isEnabled = false
        
        
        // To visualize the on-going barcode capturing process on screen, setup a data capture view that renders the
        // camera preview. The view must be connected to the data capture context.
        captureView = DataCaptureView(context: context, frame: view.bounds)
        captureView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
        view.addSubview(captureView)
        
      

        // Add a barcode capture overlay to the data capture view to render the location of captured barcodes on top of
        // the video preview. This is optional, butsx recommended for better visual feedback.
        overlay = BarcodeCaptureOverlay(barcodeCapture: barcodeCapture, view: captureView, style: .frame)
        overlay.viewfinder = RectangularViewfinder(style: .square, lineStyle: .light)
    }

    private func showResult(_ result: String, completion: @escaping () -> Void) {
        
        print("Reading.. \(result)")
        let month: Int
        let year: Int
        
        let components = result.components(separatedBy: "17")
        
        let firstComponents = components[0].components(separatedBy: "01")
        
        let stringProductID = String(firstComponents[1])
        let stringDate = String(components[1].prefix(4))
        
        print("Date recognised: \(stringDate)")
        
        if(stringDate.count < 4){
            failedRec { [weak self] in
                self?.barcodeCapture.isEnabled = true
            }
            return
        }
        
        let first = Int(stringDate.prefix(2))
        
        if(first!>12){
            year = first! + 2000
            month = (Int(stringDate.suffix(2)))!
        } else {
            month = first!
            year = (Int(stringDate.suffix(2)))! + 2000
        }
        
        print("Data Matrix: \(result)")
        print("Product ID: \(stringProductID)")
        print("Month: \(month) Year: \(year)")
        
        
        let utterance = AVSpeechUtterance(string: "This product expires on month: \(month) in the Year: \(year)")
        utterance.voice = AVSpeechSynthesisVoice(language: "en-US")
        utterance.rate = 0.45
        utterance.volume = 100

        let synthesizer = AVSpeechSynthesizer()
        synthesizer.speak(utterance)
        
        DispatchQueue.main.async {
            sleep(1)
            
            while(synthesizer.isSpeaking){
                continue
            }
            completion()
        }
    }
    
    private func failedRec(completion: @escaping () -> Void) {
        let utterance = AVSpeechUtterance(string: "This product is not recognised by the GS1 standard")
        utterance.voice = AVSpeechSynthesisVoice(language: "en-US")
        utterance.rate = 0.45
        utterance.volume = 100

        let synthesizer = AVSpeechSynthesizer()
        synthesizer.speak(utterance)
        
        
        DispatchQueue.main.async {
            sleep(1)
            
            while(synthesizer.isSpeaking){
                continue
            }
            completion()
    
           // let alert = UIAlertController(title: result, message: nil, preferredStyle: .alert)
          //  alert.addAction(UIAlertAction(title: "OK", style: .default, handler: { _ in completion() }))
          //  self.present(alert, animated: true, completion: nil)
        }
    }
    
    private func startTutorial(){
        
        let utterance = AVSpeechUtterance(string: "Welcome!   Start moving the product slowly to scan the QRCode")
        utterance.voice = AVSpeechSynthesisVoice(language: "en-US")
        utterance.rate = 0.5
        utterance.volume = 100
        utterance.preUtteranceDelay = 0

        let synthesizer = AVSpeechSynthesizer()
        synthesizer.speak(utterance)
        
        while(synthesizer.isSpeaking){
                continue
        }
        
    }

}

// MARK: - BarcodeCaptureListener

extension ViewController: BarcodeCaptureListener {

    func barcodeCapture(_ barcodeCapture: BarcodeCapture,
                        didScanIn session: BarcodeCaptureSession,
                        frameData: FrameData) {
        guard let barcode = session.newlyRecognizedBarcodes.first else {
            return
        }

        // Stop recognizing barcodes for as long as we are displaying the result. There won't be any new results until
        // the capture mode is enabled again. Note that disabling the capture mode does not stop the camera, the camera
        // continues to stream frames until it is turned off.
        barcodeCapture.isEnabled = false

        // If you are not disabling barcode capture here and want to continue scanning, consider setting the
        // codeDuplicateFilter when creating the barcode capture settings to around 500 or even -1 if you do not want
        // codes to be scanned more than once.

        // Get the human readable name of the symbology and assemble the result to be shown.
        let symbology = SymbologyDescription(symbology: barcode.symbology).readableName
        
        

        var result = ""
        if let data = barcode.data {
            result += "\(data) "
        }
        result += "(\(symbology))"
        
        if(symbology == "Data Matrix" && (barcode.data?.contains("17"))!){
            showResult(result) { [weak self] in
                // Enable recognizing barcodes when the result is not shown anymore.
                self?.barcodeCapture.isEnabled = true
            }
        } else {
            failedRec { [weak self] in
                // Enable recognizing barcodes when the result is not shown anymore.
                self?.barcodeCapture.isEnabled = true
            }
        }
        
    
    
    }

}
