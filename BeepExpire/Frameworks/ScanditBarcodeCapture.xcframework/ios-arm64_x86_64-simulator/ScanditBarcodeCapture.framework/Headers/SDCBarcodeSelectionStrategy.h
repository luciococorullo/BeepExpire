/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionStrategy)
@protocol SDCBarcodeSelectionStrategy <NSObject>
@property (nonatomic, nonnull, readonly) NSString *JSONString;
@end

NS_SWIFT_NAME(BarcodeSelectionAutoSelectionStrategy)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionAutoSelectionStrategy : NSObject <SDCBarcodeSelectionStrategy>
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)autoSelectionStrategy;

@end

NS_SWIFT_NAME(BarcodeSelectionManualSelectionStrategy)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionManualSelectionStrategy : NSObject <SDCBarcodeSelectionStrategy>
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)manualSelectionStrategy;

@end

NS_ASSUME_NONNULL_END
