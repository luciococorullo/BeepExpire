/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <CoreGraphics/CoreGraphics.h>
#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

struct SDCQuadrilateral {
    CGPoint topLeft;
    CGPoint topRight;
    CGPoint bottomRight;
    CGPoint bottomLeft;
} NS_SWIFT_NAME(Quadrilateral);
typedef struct __attribute__((objc_boxable)) SDCQuadrilateral SDCQuadrilateral;

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromQuadrilateral(SDCQuadrilateral quadrilateral) NS_SWIFT_NAME(getter:SDCQuadrilateral.jsonString(self:));
SDC_EXTERN BOOL SDCQuadrilateralFromJSONString(NSString *_Nonnull JSONString, SDCQuadrilateral *_Nonnull quadrilateral);
// clang-format on
