/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCChannel) {
    SDCChannelY,
    SDCChannelU,
    SDCChannelV,
    SDCChannelR,
    SDCChannelG,
    SDCChannelB,
    SDCChannelA
} NS_SWIFT_NAME(Channel);
// clang-format on

NS_SWIFT_NAME(ImagePlane)
SDC_EXPORTED_SYMBOL
@interface SDCImagePlane : NSObject

@property (nonatomic, nonnull, readonly) uint8_t const *data;
@property (nonatomic, readonly) SDCChannel channel;
@property (nonatomic, readonly) NSUInteger subsamplingX;
@property (nonatomic, readonly) NSUInteger subsamplingY;
@property (nonatomic, readonly) NSUInteger rowStride;
@property (nonatomic, readonly) NSUInteger pixelStride;

@end

@class UIImage;

NS_SWIFT_NAME(ImageBuffer)
SDC_EXPORTED_SYMBOL
@interface SDCImageBuffer : NSObject

@property (nonatomic, nonnull, readonly) NSArray<SDCImagePlane *> *planes;
@property (nonatomic, readonly) NSUInteger width;
@property (nonatomic, readonly) NSUInteger height;
@property (nonatomic, nullable, readonly) UIImage *image;
- (nullable UIImage *)toUIImage DEPRECATED_MSG_ATTRIBUTE("Use image instead");

@end

NS_SWIFT_NAME(FrameData)
@protocol SDCFrameData <NSObject>

@property (nonatomic, nonnull, readonly) NSArray<SDCImageBuffer *> *imageBuffers;

@end
