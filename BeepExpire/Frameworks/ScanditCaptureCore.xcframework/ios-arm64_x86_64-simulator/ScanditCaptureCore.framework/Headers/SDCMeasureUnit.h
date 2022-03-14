/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCMeasureUnit) {
    SDCMeasureUnitPixel,
    SDCMeasureUnitDIP NS_SWIFT_NAME(dip),
    SDCMeasureUnitFraction,
} NS_SWIFT_NAME(MeasureUnit);

typedef NS_CLOSED_ENUM(NSUInteger, SDCSizingMode) {
    SDCSizingModeWidthAndHeight,
    SDCSizingModeWidthAndAspectRatio,
    SDCSizingModeHeightAndAspectRatio,
    SDCSizingModeShorterDimensionAndAspectRatio,
} NS_SWIFT_NAME(SizingMode);
// clang-format on

struct SDCFloatWithUnit {
    CGFloat value;
    SDCMeasureUnit unit;
} NS_SWIFT_NAME(FloatWithUnit);
typedef struct __attribute__((objc_boxable)) SDCFloatWithUnit SDCFloatWithUnit;

static inline SDCFloatWithUnit SDCFloatWithUnitMake(CGFloat value, SDCMeasureUnit unit)
    NS_SWIFT_UNAVAILABLE("Use FloatWithUnit(value:unit:)") {
    SDCFloatWithUnit result;
    result.value = value;
    result.unit = unit;
    return result;
}

SDC_EXTERN const SDCFloatWithUnit SDCFloatWithUnitZero NS_SWIFT_NAME(FloatWithUnit.zero);
SDC_EXTERN const SDCFloatWithUnit SDCFloatWithUnitNull NS_SWIFT_NAME(FloatWithUnit.null);

SDC_EXTERN BOOL SDCFloatWithUnitIsNull(SDCFloatWithUnit floatWithUnit);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromFloatWithUnit(SDCFloatWithUnit floatWithUnit) NS_SWIFT_NAME(getter:SDCFloatWithUnit.jsonString(self:));
// clang-format on

struct SDCSizeWithUnit {
    SDCFloatWithUnit width;
    SDCFloatWithUnit height;
} NS_SWIFT_NAME(SizeWithUnit);
typedef struct __attribute__((objc_boxable)) SDCSizeWithUnit SDCSizeWithUnit;

static inline SDCSizeWithUnit SDCSizeWithUnitMake(SDCFloatWithUnit width, SDCFloatWithUnit height)
    NS_SWIFT_UNAVAILABLE("Use SizeWithUnit(width:height:)") {
    SDCSizeWithUnit result;
    result.width = width;
    result.height = height;
    return result;
}

SDC_EXTERN const SDCSizeWithUnit SDCSizeWithUnitZero NS_SWIFT_NAME(SizeWithUnit.zero);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromSizeWithUnit(SDCSizeWithUnit sizeWithUnit) NS_SWIFT_NAME(getter:SDCSizeWithUnit.jsonString(self:));
// clang-format on

struct SDCPointWithUnit {
    SDCFloatWithUnit x;
    SDCFloatWithUnit y;
} NS_SWIFT_NAME(PointWithUnit);
typedef struct __attribute__((objc_boxable)) SDCPointWithUnit SDCPointWithUnit;

static inline SDCPointWithUnit SDCPointWithUnitMake(SDCFloatWithUnit x, SDCFloatWithUnit y)
    NS_SWIFT_UNAVAILABLE("Use PointWithUnit(x:y:)") {
    SDCPointWithUnit result;
    result.x = x;
    result.y = y;
    return result;
}

SDC_EXTERN const SDCPointWithUnit SDCPointWithUnitZero NS_SWIFT_NAME(PointWithUnit.zero);
SDC_EXTERN const SDCPointWithUnit SDCPointWithUnitNull NS_SWIFT_NAME(PointWithUnit.null);

// clang-format off
SDC_EXTERN BOOL SDCPointWithUnitIsNull(SDCPointWithUnit pointWithUnit) NS_SWIFT_NAME(getter:SDCPointWithUnit.isNull(self:));

SDC_EXTERN NSString *_Nonnull NSStringFromPointWithUnit(SDCPointWithUnit pointWithUnit) NS_SWIFT_NAME(getter:SDCPointWithUnit.jsonString(self:));
SDC_EXTERN BOOL SDCPointWithUnitFromJSONString(NSString *_Nonnull JSONString, SDCPointWithUnit *_Nonnull pointWithUnit);
// clang-format on

struct SDCRectWithUnit {
    SDCPointWithUnit origin;
    SDCSizeWithUnit size;
} NS_SWIFT_NAME(RectWithUnit);
typedef struct __attribute__((objc_boxable)) SDCRectWithUnit SDCRectWithUnit;

static inline SDCRectWithUnit SDCRectWithUnitMake(SDCPointWithUnit origin, SDCSizeWithUnit size)
    NS_SWIFT_UNAVAILABLE("Use RectWithUnit(origin:size:)") {
    SDCRectWithUnit result;
    result.origin = origin;
    result.size = size;
    return result;
}

SDC_EXTERN const SDCRectWithUnit SDCRectWithUnitZero NS_SWIFT_NAME(RectWithUnit.zero);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromRectWithUnit(SDCRectWithUnit rectWithUnit) NS_SWIFT_NAME(getter:SDCRectWithUnit.jsonString(self:));
// clang-format on

struct SDCMarginsWithUnit {
    SDCFloatWithUnit left;
    SDCFloatWithUnit top;
    SDCFloatWithUnit right;
    SDCFloatWithUnit bottom;
} NS_SWIFT_NAME(MarginsWithUnit);
typedef struct __attribute__((objc_boxable)) SDCMarginsWithUnit SDCMarginsWithUnit;

static inline SDCMarginsWithUnit SDCMarginsWithUnitMake(SDCFloatWithUnit left, SDCFloatWithUnit top,
                                                        SDCFloatWithUnit right,
                                                        SDCFloatWithUnit bottom)
    NS_SWIFT_UNAVAILABLE("Use MarginsWithUnit(left:top:right:bottom:)") {
    SDCMarginsWithUnit result;
    result.left = left;
    result.top = top;
    result.right = right;
    result.bottom = bottom;
    return result;
}

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromMarginsWithUnit(SDCMarginsWithUnit marginsWithUnit) NS_SWIFT_NAME(getter:SDCMarginsWithUnit.jsonString(self:));
// clang-format on

struct SDCSizeWithAspect {
    SDCFloatWithUnit size;
    CGFloat aspect;
} NS_SWIFT_NAME(SizeWithAspect);
typedef struct __attribute__((objc_boxable)) SDCSizeWithAspect SDCSizeWithAspect;

static inline SDCSizeWithAspect SDCSizeWithAspectMake(SDCFloatWithUnit size, CGFloat aspect)
    NS_SWIFT_UNAVAILABLE("Use SizeWithAspect(size:aspect:)") {
    SDCSizeWithAspect result;
    result.size = size;
    result.aspect = aspect;
    return result;
}

SDC_EXTERN const SDCSizeWithAspect SDCSizeWithAspectZero NS_SWIFT_NAME(SizeWithAspect.zero);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromSizeWithAspect(SDCSizeWithAspect sizeWithAspect) NS_SWIFT_NAME(getter:SDCSizeWithAspect.jsonString(self:));
// clang-format on
