/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCFrameSourceDeserializer;
@class SDCCameraSettings;
@protocol SDCDataCaptureModeDeserializer;
@protocol SDCFrameSourceDeserializerDelegate;
@protocol SDCFrameSource;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(FrameSourceDeserializer)
SDC_EXPORTED_SYMBOL
@interface SDCFrameSourceDeserializer : NSObject

@property (nonatomic, weak, nullable) id<SDCFrameSourceDeserializerDelegate> delegate;
@property (nonatomic, readonly) NSArray<NSString *> *warnings;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

// clang-format off
+ (instancetype)frameSourceDeserializerWithModeDeserializers:(NSArray<id<SDCDataCaptureModeDeserializer>> *)modeDeserializers;
// clang-format on

- (nullable id<SDCFrameSource>)frameSourceFromJSONString:(NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;
- (nullable id<SDCFrameSource>)updateFrameSource:(id<SDCFrameSource>)frameSource
                                  fromJSONString:(NSString *)JSONString
                                           error:(NSError *_Nullable *_Nullable)error;

- (nullable SDCCameraSettings *)cameraSettingsFromJSONString:(NSString *)JSONString
                                                       error:(NSError *_Nullable *_Nullable)error;
- (nullable SDCCameraSettings *)updateCameraSettings:(SDCCameraSettings *)settings
                                      fromJSONString:(NSString *)JSONString
                                               error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
