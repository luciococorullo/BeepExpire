/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionType)
@protocol SDCBarcodeSelectionType <NSObject>
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

NS_ASSUME_NONNULL_END
