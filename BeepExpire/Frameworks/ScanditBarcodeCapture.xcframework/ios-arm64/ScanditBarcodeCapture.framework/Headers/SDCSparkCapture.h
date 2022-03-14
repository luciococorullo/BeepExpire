/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureMode.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCDataCaptureContext;
@class SDCCameraSettings;
@class SDCSparkCaptureSettings;
@class SDCSparkCaptureSession;
@class SDCSparkCaptureFeedback;
@class SDCSparkCapture;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SparkCaptureListener)
@protocol SDCSparkCaptureListener <NSObject>

@required

- (void)sparkCapture:(SDCSparkCapture *)sparkCapture
    didScanInSession:(SDCSparkCaptureSession *)session
           frameData:(id<SDCFrameData>)frameData;

@optional

- (void)sparkCapture:(SDCSparkCapture *)sparkCapture
    didUpdateSession:(SDCSparkCaptureSession *)session
           frameData:(id<SDCFrameData>)frameData;

- (void)didStartObservingSparkCapture:(SDCSparkCapture *)sparkCapture;

- (void)didStopObservingSparkCapture:(SDCSparkCapture *)sparkCapture;

@end

NS_SWIFT_NAME(SparkCapture)
SDC_EXPORTED_SYMBOL
@interface SDCSparkCapture : NSObject <SDCDataCaptureMode>

@property (nonatomic, nullable, readonly) SDCDataCaptureContext *context;
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;
@property (nonatomic, strong, nonnull) SDCSparkCaptureFeedback *feedback;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)sparkCaptureWithContext:(nullable SDCDataCaptureContext *)context
                               settings:(nonnull SDCSparkCaptureSettings *)settings;

+ (nullable instancetype)sparkCaptureFromJSONString:(nonnull NSString *)JSONString
                                            context:(nonnull SDCDataCaptureContext *)context
                                              error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:context:));

- (void)applySettings:(nonnull SDCSparkCaptureSettings *)settings
    completionHandler:(nullable void (^)(void))completionHandler;

- (void)addListener:(nonnull id<SDCSparkCaptureListener>)listener NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCSparkCaptureListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
