/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;
@class SDCCamera;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CameraSwitchControl)
SDC_EXPORTED_SYMBOL
@interface SDCCameraSwitchControl : NSObject <SDCControl>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@property (nonatomic, strong, nonnull) UIImage *primaryCameraImage;
@property (nonatomic, strong, nonnull) UIImage *primaryCameraPressedImage;
@property (nonatomic, strong, nonnull) UIImage *secondaryCameraImage;
@property (nonatomic, strong, nonnull) UIImage *secondaryCameraPressedImage;

@property (class, nonatomic, nonnull, readonly) UIImage *defaultPrimaryCameraImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultPrimaryCameraPressedImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultSecondaryCameraImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultSecondaryCameraPressedImage;

@property (nonatomic, strong, nonnull, readonly) SDCCamera *primaryCamera;
@property (nonatomic, strong, nonnull, readonly) SDCCamera *secondaryCamera;

- (nonnull instancetype)initWithPrimaryCamera:(nonnull SDCCamera *)primaryCamera
                              secondaryCamera:(nonnull SDCCamera *)secondaryCamera;

+ (nullable instancetype)cameraSwitchControlFromJSONString:(nonnull NSString *)JSONString
                                                     error:(NSError *_Nullable *_Nullable)error;

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
