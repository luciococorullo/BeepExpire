/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCDataCaptureContext;
@class SDCCameraSettings;
@class SDCBarcodeSelectionSettings;
@class SDCBarcodeSelectionSession;
@class SDCBarcodeSelectionFeedback;

@class SDCBarcodeSelection;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionListener)
@protocol SDCBarcodeSelectionListener <NSObject>

@required

- (void)barcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
      didUpdateSelection:(nonnull SDCBarcodeSelectionSession *)session
               frameData:(nullable id<SDCFrameData>)frameData;

@optional

- (void)barcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
        didUpdateSession:(nonnull SDCBarcodeSelectionSession *)session
               frameData:(nullable id<SDCFrameData>)frameData;

- (void)didStartObservingBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection;

- (void)didStopObservingBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection;

@end

NS_SWIFT_NAME(BarcodeSelection)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelection : NSObject <SDCDataCaptureMode>

@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
@property (nonatomic, assign) SDCPointWithUnit pointOfInterest;
@property (nonatomic, strong, nonnull) SDCBarcodeSelectionFeedback *feedback;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)barcodeSelectionWithContext:(nullable SDCDataCaptureContext *)context
                                   settings:(nonnull SDCBarcodeSelectionSettings *)settings
    NS_SWIFT_NAME(init(context:settings:));
;

+ (nullable instancetype)barcodeSelectionFromJSONString:(nonnull NSString *)JSONString
                                                context:(nonnull SDCDataCaptureContext *)context
                                                  error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

- (void)applySettings:(nonnull SDCBarcodeSelectionSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

- (void)addListener:(nonnull id<SDCBarcodeSelectionListener>)listener
    NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCBarcodeSelectionListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (void)reset;
- (void)unfreezeCamera;

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
