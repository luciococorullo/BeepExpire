/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class UIColor;
@class SDCSizeWithUnitAndAspect;
@class SDCRectangularViewfinderAnimation;

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(NSUInteger, SDCRectangularViewfinderStyle) {
    SDCRectangularViewfinderStyleLegacy,
    SDCRectangularViewfinderStyleSquare,
    SDCRectangularViewfinderStyleRounded,
} NS_SWIFT_NAME(RectangularViewfinderStyle);

// clang-format off
SDC_EXTERN
NSString *_Nonnull NSStringFromRectangularViewfinderStyle(SDCRectangularViewfinderStyle style) NS_SWIFT_NAME(getter:SDCRectangularViewfinderStyle.jsonString(self:));
SDC_EXTERN BOOL SDCRectangularViewfinderStyleFromJSONString(NSString *_Nonnull JSONString,
                                                            SDCRectangularViewfinderStyle *_Nonnull style);
// clang-format on

typedef NS_CLOSED_ENUM(NSUInteger, SDCRectangularViewfinderLineStyle) {
    SDCRectangularViewfinderLineStyleBold,
    SDCRectangularViewfinderLineStyleLight,
} NS_SWIFT_NAME(RectangularViewfinderLineStyle);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromRectangularViewfinderLineStyle(SDCRectangularViewfinderLineStyle style) NS_SWIFT_NAME(getter:SDCRectangularViewfinderLineStyle.jsonString(self:));
SDC_EXTERN BOOL SDCRectangularViewfinderLineStyleFromJSONString(NSString *_Nonnull JSONString,
                                                                SDCRectangularViewfinderLineStyle *_Nonnull style);
// clang-format on

NS_SWIFT_NAME(RectangularViewfinder)
SDC_EXPORTED_SYMBOL
@interface SDCRectangularViewfinder : NSObject <SDCViewfinder>

@property (nonatomic, strong, nonnull) UIColor *color;
@property (nonatomic, strong, nonnull) UIColor *disabledColor;
@property (nonatomic, readonly) SDCRectangularViewfinderStyle style;
@property (nonatomic, readonly) SDCRectangularViewfinderLineStyle lineStyle;
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;
@property (nonatomic, assign) CGFloat dimming;
@property (nonatomic, assign) CGFloat disabledDimming;
@property (nonatomic, strong, nullable) SDCRectangularViewfinderAnimation *animation;

+ (nonnull instancetype)viewfinder;
+ (nonnull instancetype)viewfinderWithStyle:(SDCRectangularViewfinderStyle)style;
+ (nonnull instancetype)viewfinderWithStyle:(SDCRectangularViewfinderStyle)style
                                  lineStyle:(SDCRectangularViewfinderLineStyle)lineStyle;

- (void)setSize:(SDCSizeWithUnit)size;
- (void)setWidth:(SDCFloatWithUnit)width aspectRatio:(CGFloat)heightToWidthAspectRatio;
- (void)setHeight:(SDCFloatWithUnit)height aspectRatio:(CGFloat)widthToHeightAspectRatio;
- (void)setShorterDimension:(CGFloat)fraction aspectRatio:(CGFloat)aspectRatio;

@end

NS_ASSUME_NONNULL_END
