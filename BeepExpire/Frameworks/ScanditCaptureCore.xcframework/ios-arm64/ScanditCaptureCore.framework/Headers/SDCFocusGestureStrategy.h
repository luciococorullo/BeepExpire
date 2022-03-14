/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

typedef NS_CLOSED_ENUM(NSUInteger, SDCFocusGestureStrategy) {
    SDCFocusGestureStrategyNone,
    SDCFocusGestureStrategyManual,
    SDCFocusGestureStrategyManualUntilCapture,
    SDCFocusGestureStrategyAutoOnLocation
} NS_SWIFT_NAME(FocusGestureStrategy);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromFocusGestureStrategy(SDCFocusGestureStrategy focusGestureStrategy) NS_SWIFT_NAME(getter:SDCFocusGestureStrategy.jsonString(self:));
SDC_EXTERN BOOL SDCFocusGestureStrategyFromJSONString(NSString *_Nonnull JSONString, SDCFocusGestureStrategy *_Nonnull focusGestureStrategy);
// clang-format on
