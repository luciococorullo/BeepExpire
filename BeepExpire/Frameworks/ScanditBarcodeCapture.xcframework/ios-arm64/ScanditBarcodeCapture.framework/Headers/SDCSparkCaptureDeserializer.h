/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCDataCaptureModeDeserializer.h>

@class SDCSparkCapture;
@class SDCDataCaptureContext;
@class SDCSparkCaptureSettings;
@class SDCSparkCaptureOverlay;
@protocol SDCSparkCaptureDeserializerDelegate;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SparkCaptureDeserializer)
@interface SDCSparkCaptureDeserializer : NSObject <SDCDataCaptureModeDeserializer>

@property (nonatomic, weak, nullable) id<SDCSparkCaptureDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)sparkCaptureDeserializer;

- (nullable SDCSparkCapture *)modeFromJSONString:(NSString *)JSONString
                                     withContext:(SDCDataCaptureContext *)context
                                           error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCSparkCapture *)updateMode:(SDCSparkCapture *)sparkCapture
                          fromJSONString:(NSString *)JSONString
                                   error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCSparkCaptureSettings *)settingsFromJSONString:(NSString *)JSONString
                                                       error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCSparkCaptureSettings *)updateSettings:(SDCSparkCaptureSettings *)settings
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
