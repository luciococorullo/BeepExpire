/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <CoreMedia/CoreMedia.h>
#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCFrameSource.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ImageFrameSource)
SDC_EXPORTED_SYMBOL
@interface SDCImageFrameSource : NSObject <SDCFrameSource>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (nonnull instancetype)frameSourceWithImage:(nonnull UIImage *)image;

- (void)switchToDesiredState:(SDCFrameSourceState)state;

@end

NS_ASSUME_NONNULL_END
