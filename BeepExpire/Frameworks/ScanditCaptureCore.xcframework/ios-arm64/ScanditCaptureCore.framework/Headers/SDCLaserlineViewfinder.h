/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class UIColor;

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(NSUInteger, SDCLaserlineViewfinderStyle) {
    SDCLaserlineViewfinderStyleLegacy,
    SDCLaserlineViewfinderStyleAnimated,
} NS_SWIFT_NAME(LaserlineViewfinderStyle);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromLaserlineViewfinderStyle(SDCLaserlineViewfinderStyle style) NS_SWIFT_NAME(getter:SDCLaserlineViewfinderStyle.jsonString(self:));
SDC_EXTERN BOOL SDCLaserlineViewfinderStyleFromJSONString(NSString *_Nonnull JSONString,
                                                          SDCLaserlineViewfinderStyle *_Nonnull style);
// clang-format on

NS_SWIFT_NAME(LaserlineViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCLaserlineViewfinder : NSObject <SDCViewfinder>

+ (nonnull instancetype)viewfinder;

+ (nonnull instancetype)viewfinderWithStyle:(SDCLaserlineViewfinderStyle)style;

@property (nonatomic, assign) SDCFloatWithUnit width;
@property (nonatomic, strong, nonnull) UIColor *enabledColor;
@property (nonatomic, strong, nonnull) UIColor *disabledColor;
@property (nonatomic, readonly) SDCLaserlineViewfinderStyle style;

@end

NS_ASSUME_NONNULL_END
