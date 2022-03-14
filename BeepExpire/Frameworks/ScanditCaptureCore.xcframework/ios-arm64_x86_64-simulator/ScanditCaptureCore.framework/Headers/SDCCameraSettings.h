/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCFocusGestureStrategy.h>

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCVideoResolution) {
    SDCVideoResolutionHD NS_SWIFT_NAME(hd) = 0,
    SDCVideoResolutionFullHD = 1,
    SDCVideoResolutionAuto = 2,
    SDCVideoResolutionUHD4K NS_SWIFT_NAME(uhd4k) = 3,
} NS_SWIFT_NAME(VideoResolution);

SDC_EXTERN NSString *_Nonnull NSStringFromVideoResolution(SDCVideoResolution videoResolution) NS_SWIFT_NAME(getter:SDCVideoResolution.jsonString(self:));
SDC_EXTERN BOOL SDCVideoResolutionFromJSONString(NSString *_Nonnull JSONString, SDCVideoResolution *_Nonnull videoResolution);

typedef NS_CLOSED_ENUM(NSUInteger, SDCFocusRange) {
    SDCFocusRangeFull,
    SDCFocusRangeFar,
    SDCFocusRangeNear,
} NS_SWIFT_NAME(FocusRange);

SDC_EXTERN NSString *_Nonnull NSStringFromFocusRange(SDCFocusRange focusRange) NS_SWIFT_NAME(getter:SDCFocusRange.jsonString(self:));
SDC_EXTERN BOOL SDCFocusRangeFromJSONString(NSString *_Nonnull JSONString, SDCFocusRange *_Nonnull focusRange);
// clang-format on

SDC_EXTERN const CGFloat SDCCurrentZoomFactor NS_SWIFT_NAME(CurrentZoomFactor);

NS_SWIFT_NAME(CameraSettings)
SDC_EXPORTED_SYMBOL
@interface SDCCameraSettings : NSObject

- (instancetype)init;
- (instancetype)initWithSettings:(nonnull SDCCameraSettings *)settings;
- (void)setValue:(nonnull id)value forProperty:(nonnull NSString *)property;
- (nullable id)valueForProperty:(nonnull NSString *)property;

@property (nonatomic, assign) SDCVideoResolution preferredResolution;
@property (nonatomic, assign) CGFloat maxFrameRate DEPRECATED_MSG_ATTRIBUTE(
    "The frame rate is optimized internally based on the used device. Setting max frame rate may "
    "have no effect due to camera or device-specific restrictions.");
@property (nonatomic, assign) CGFloat zoomFactor;
@property (nonatomic, assign) SDCFocusRange focusRange;
@property (nonatomic, assign) SDCFocusGestureStrategy focusGestureStrategy;
@property (nonatomic, assign) BOOL shouldPreferSmoothAutoFocus;
@property (nonatomic, assign) CGFloat zoomGestureZoomFactor;
@property (nonatomic, assign) CGFloat torchLevel;

@end

NS_ASSUME_NONNULL_END
