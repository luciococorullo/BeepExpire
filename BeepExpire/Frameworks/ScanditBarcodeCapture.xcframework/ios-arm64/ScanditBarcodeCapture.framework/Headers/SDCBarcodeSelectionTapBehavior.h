/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionTapBehavior) {
    SDCBarcodeSelectionTapBehaviorToggleSelection,
    SDCBarcodeSelectionTapBehaviorRepeatSelection
} NS_SWIFT_NAME(BarcodeSelectionTapBehavior);

SDC_EXTERN BOOL SDCBarcodeSelectionTapBehaviorFromJSONString(NSString *_Nonnull JSONString,
                                                             SDCBarcodeSelectionTapBehavior *_Nonnull tapBehavior);

SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionTapBehavior(SDCBarcodeSelectionTapBehavior tapBehavior) NS_SWIFT_NAME(getter:SDCBarcodeSelectionTapBehavior.jsonString(self:));

// clang-format on
