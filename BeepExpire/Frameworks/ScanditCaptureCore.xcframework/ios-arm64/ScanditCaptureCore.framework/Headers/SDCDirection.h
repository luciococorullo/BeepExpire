/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCDirection) {
    SDCDirectionLeftToRight,
    SDCDirectionRightToLeft,
    SDCDirectionHorizontal,
    SDCDirectionTopToBottom,
    SDCDirectionBottomToTop,
    SDCDirectionVertical,
    SDCDirectionNone
} NS_SWIFT_NAME(Direction);

SDC_EXTERN NSString *_Nonnull NSStringFromDirection(SDCDirection direction) NS_SWIFT_NAME(getter:SDCDirection.jsonString(self:));
// clang-format on
