/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionType.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionTapBehavior.h>
#import <ScanditBarcodeCapture/SDCBarcodeSelectionFreezeBehavior.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionTapSelection)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionTapSelection : NSObject <SDCBarcodeSelectionType>

@property (nonatomic) SDCBarcodeSelectionFreezeBehavior freezeBehavior;
@property (nonatomic) SDCBarcodeSelectionTapBehavior tapBehavior;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)tapSelection;
+ (instancetype)tapSelectionWithFreezeBehavior:(SDCBarcodeSelectionFreezeBehavior)freezeBehavior
                                   tapBehavior:(SDCBarcodeSelectionTapBehavior)tapBehavior;

@end

NS_ASSUME_NONNULL_END
