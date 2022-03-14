/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(LocationSelection)
@protocol SDCLocationSelection <NSObject>
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

NS_SWIFT_NAME(RadiusLocationSelection)
SDC_EXPORTED_SYMBOL
@interface SDCRadiusLocationSelection : NSObject <SDCLocationSelection>

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)locationSelectionWithRadius:(SDCFloatWithUnit)radius;

@property (nonatomic, readonly) SDCFloatWithUnit radius;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

@class SDCSizeWithUnitAndAspect;

NS_SWIFT_NAME(RectangularLocationSelection)
SDC_EXPORTED_SYMBOL
@interface SDCRectangularLocationSelection : NSObject <SDCLocationSelection>
@property (nonatomic, readonly) SDCSizeWithUnitAndAspect *sizeWithUnitAndAspect;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)locationSelectionWithSize:(SDCSizeWithUnit)size;
+ (instancetype)locationSelectionWithWidth:(SDCFloatWithUnit)width
                               aspectRatio:(CGFloat)heightToWidthAspectRatio;
+ (instancetype)locationSelectionWithHeight:(SDCFloatWithUnit)height
                                aspectRatio:(CGFloat)widthToHeightAspectRatio;

@end

NS_ASSUME_NONNULL_END
