/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCAnchor) {
    SDCAnchorTopLeft,
    SDCAnchorTopCenter,
    SDCAnchorTopRight,
    SDCAnchorCenterLeft,
    SDCAnchorCenter,
    SDCAnchorCenterRight,
    SDCAnchorBottomLeft,
    SDCAnchorBottomCenter,
    SDCAnchorBottomRight,
} NS_SWIFT_NAME(Anchor);

SDC_EXTERN NSString *_Nonnull NSStringFromAnchor(SDCAnchor anchor) NS_SWIFT_NAME(getter:SDCAnchor.jsonString(self:));
SDC_EXTERN BOOL SDCAnchorFromJSONString(NSString *_Nonnull JSONString, SDCAnchor *_Nonnull anchor);
// clang-format on
