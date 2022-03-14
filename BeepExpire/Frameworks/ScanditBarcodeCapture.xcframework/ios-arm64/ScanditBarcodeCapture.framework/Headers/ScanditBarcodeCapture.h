/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

FOUNDATION_EXPORT double ScanditBarcodeCaptureVersionNumber;

FOUNDATION_EXPORT const unsigned char ScanditBarcodeCaptureVersionString[];

// clang-format off
#import <ScanditCaptureCore/ScanditCaptureCore.h>
#import <ScanditBarcodeCapture/SDCBarcode.h>
#import <ScanditBarcodeCapture/SDCBarcodeCapture.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureDeserializer.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureDeserializerDelegate.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureFeedback.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureOverlay.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureSession.h>
#import <ScanditBarcodeCapture/SDCBarcodeCaptureSettings.h>
#import <ScanditBarcodeCapture/SDCBarcodeInfo.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelection.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionAimerSelection.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionBasicOverlay.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionDeserializer.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionDeserializerDelegate.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionFeedback.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionFreezeBehavior.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionSession.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionSettings.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionStrategy.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionTapBehavior.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionTapSelection.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionType.h>
#import <ScanditBarcodeCapture/SDCBarcodeTracking.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingAdvancedOverlay.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingBasicOverlay.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingDeserializer.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingDeserializerDelegate.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingSession.h>
#import <ScanditBarcodeCapture/SDCBarcodeTrackingSettings.h>
#import <ScanditBarcodeCapture/SDCCompositeType.h>
#import <ScanditBarcodeCapture/SDCCompositeTypeDescription.h>
#import <ScanditBarcodeCapture/SDCLocalizedOnlyBarcode.h>
#import <ScanditBarcodeCapture/SDCSparkCapture.h>
#import <ScanditBarcodeCapture/SDCSparkCaptureDeserializer.h>
#import <ScanditBarcodeCapture/SDCSparkCaptureDeserializerDelegate.h>
#import <ScanditBarcodeCapture/SDCSparkCaptureFeedback.h>
#import <ScanditBarcodeCapture/SDCSparkCaptureSession.h>
#import <ScanditBarcodeCapture/SDCSparkCaptureSettings.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>
#import <ScanditBarcodeCapture/SDCSymbologyDescription.h>
#import <ScanditBarcodeCapture/SDCSymbologySettings.h>
#import <ScanditBarcodeCapture/SDCTrackedBarcode.h>
#import <ScanditBarcodeCapture/SDCTrackedBarcodeInfo.h>

// clang-format on
