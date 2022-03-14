/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>

@class UIColor;
// clang-format off
SDC_EXTERN NSString *_Nonnull SDCStringFromColor(UIColor *_Nonnull color) NS_SWIFT_NAME(getter:UIColor.sdcHexString(self:));
SDC_EXTERN UIColor *_Nullable SDCColorFromHexString(NSString *_Nonnull hexString) NS_SWIFT_NAME(UIColor.init(sdcHexString:));
// clang-format on
