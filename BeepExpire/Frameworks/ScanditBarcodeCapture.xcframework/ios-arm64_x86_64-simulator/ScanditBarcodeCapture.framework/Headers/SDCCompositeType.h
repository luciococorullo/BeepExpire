/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

typedef NS_OPTIONS(NSUInteger, SDCCompositeType) {
    SDCCompositeTypeA NS_SWIFT_NAME(a) = 1 << 0,
    SDCCompositeTypeB NS_SWIFT_NAME(b) = 1 << 1,
    SDCCompositeTypeC NS_SWIFT_NAME(c) = 1 << 2,
} NS_SWIFT_NAME(CompositeType);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromCompositeType(SDCCompositeType compositeType)
    NS_SWIFT_NAME(getter:SDCCompositeType.jsonString(self:));
SDC_EXTERN BOOL SDCCompositeTypeFromJSONString(NSString *_Nonnull JSONString,
                                               SDCCompositeType *_Nonnull compositeType);
// clang-format on
