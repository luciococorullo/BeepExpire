/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>

@class SDCDataCaptureContext;
@class SDCBarcodeTracking;
@class SDCBarcodeTrackingSettings;
@class SDCBarcodeTrackingSession;
@class SDCCameraSettings;

@protocol SDCFrameData;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeTrackingListener)
@protocol SDCBarcodeTrackingListener <NSObject>

@required

- (void)barcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
              didUpdate:(nonnull SDCBarcodeTrackingSession *)session
              frameData:(nonnull id<SDCFrameData>)frameData;

@optional

- (void)didStartObservingBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;

- (void)didStopObservingBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;

@end

NS_SWIFT_NAME(BarcodeTracking)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTracking : NSObject <SDCDataCaptureMode>

@property (class, nonatomic, nonnull, readonly) SDCCameraSettings *recommendedCameraSettings;
@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)barcodeTrackingWithContext:(nullable SDCDataCaptureContext *)context
                                  settings:(nonnull SDCBarcodeTrackingSettings *)settings;

+ (nullable instancetype)barcodeTrackingFromJSONString:(nonnull NSString *)JSONString
                                               context:(nonnull SDCDataCaptureContext *)context
                                                 error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

- (void)applySettings:(nonnull SDCBarcodeTrackingSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;
- (void)addListener:(nonnull id<SDCBarcodeTrackingListener>)listener NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCBarcodeTrackingListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
