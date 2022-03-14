/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionType.h>

@protocol SDCBarcodeSelectionStrategy;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionAimerSelection)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionAimerSelection : NSObject <SDCBarcodeSelectionType>

@property (nonatomic, strong, nonnull) id<SDCBarcodeSelectionStrategy> selectionStrategy;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)aimerSelection;

@end

NS_ASSUME_NONNULL_END
