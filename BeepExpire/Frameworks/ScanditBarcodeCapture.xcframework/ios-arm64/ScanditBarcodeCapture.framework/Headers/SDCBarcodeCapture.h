/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCDataCaptureMode.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBarcodeCapture;
@class SDCBarcodeCaptureSession;
@class SDCBarcodeCaptureSettings;
@class SDCDataCaptureContext;
@class SDCBarcodeCaptureFeedback;
@class SDCCameraSettings;
@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureListener)
@protocol SDCBarcodeCaptureListener <NSObject>

@required

- (void)barcodeCapture:(SDCBarcodeCapture *)barcodeCapture
      didScanInSession:(SDCBarcodeCaptureSession *)session
             frameData:(id<SDCFrameData>)frameData;

@optional

- (void)barcodeCapture:(SDCBarcodeCapture *)barcodeCapture
      didUpdateSession:(SDCBarcodeCaptureSession *)session
             frameData:(id<SDCFrameData>)frameData;

- (void)didStartObservingBarcodeCapture:(SDCBarcodeCapture *)barcodeCapture;

- (void)didStopObservingBarcodeCapture:(SDCBarcodeCapture *)barcodeCapture;

@end

NS_SWIFT_NAME(BarcodeCapture)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCapture : NSObject <SDCDataCaptureMode>

@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
@property (nonatomic, strong, nonnull) SDCBarcodeCaptureFeedback *feedback;
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
@property (nonatomic, assign) SDCPointWithUnit pointOfInterest;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)barcodeCaptureWithContext:(nullable SDCDataCaptureContext *)context
                                 settings:(nonnull SDCBarcodeCaptureSettings *)settings
    NS_SWIFT_NAME(init(context:settings:));

+ (nullable instancetype)barcodeCaptureFromJSONString:(nonnull NSString *)JSONString
                                              context:(nonnull SDCDataCaptureContext *)context
                                                error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

- (void)applySettings:(nonnull SDCBarcodeCaptureSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

- (void)addListener:(nonnull id<SDCBarcodeCaptureListener>)listener NS_SWIFT_NAME(addListener(_:));

- (void)removeListener:(nonnull id<SDCBarcodeCaptureListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
