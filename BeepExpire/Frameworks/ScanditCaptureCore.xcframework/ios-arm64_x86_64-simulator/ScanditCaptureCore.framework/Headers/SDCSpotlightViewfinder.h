/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCViewfinder.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>
#import <ScanditCaptureCore/SDCSizeWithUnitAndAspect.h>

@class UIColor;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(SpotlightViewfinder)
SDC_EXPORTED_SYMBOL
DEPRECATED_MSG_ATTRIBUTE("Use SDCRectangularViewfinder instead.")
@interface SDCSpotlightViewfinder : NSObject <SDCViewfinder>

@property (nonatomic, strong, nonnull) UIColor *enabledBorderColor;
@property (nonatomic, strong, nonnull) UIColor *disabledBorderColor;
@property (nonatomic, strong, nonnull) UIColor *backgroundColor;
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;

+ (nonnull instancetype)viewfinder NS_SWIFT_NAME(init())
    DEPRECATED_MSG_ATTRIBUTE("Use SDCRectangularViewfinder instead.");

- (void)setSize:(SDCSizeWithUnit)size;
- (void)setWidth:(SDCFloatWithUnit)width aspectRatio:(CGFloat)heightToWidthAspectRatio;
- (void)setHeight:(SDCFloatWithUnit)height aspectRatio:(CGFloat)widthToHeightAspectRatio;

@end

NS_ASSUME_NONNULL_END
