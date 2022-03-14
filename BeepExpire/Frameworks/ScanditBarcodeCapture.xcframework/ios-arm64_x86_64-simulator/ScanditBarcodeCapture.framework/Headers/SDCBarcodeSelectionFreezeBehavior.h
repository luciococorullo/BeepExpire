/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionFreezeBehavior) {
    SDCBarcodeSelectionFreezeBehaviorManual,
    SDCBarcodeSelectionFreezeBehaviorManualAndAutomatic
} NS_SWIFT_NAME(BarcodeSelectionFreezeBehavior);

SDC_EXTERN BOOL SDCBarcodeSelectionFreezeBehaviorFromJSONString(NSString *_Nonnull JSONString,
                                                                SDCBarcodeSelectionFreezeBehavior *_Nonnull freezeBehavior);

SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionFreezeBehavior(SDCBarcodeSelectionFreezeBehavior freezeBehavior) NS_SWIFT_NAME(getter:SDCBarcodeSelectionFreezeBehavior.jsonString(self:));
// clang-format on
