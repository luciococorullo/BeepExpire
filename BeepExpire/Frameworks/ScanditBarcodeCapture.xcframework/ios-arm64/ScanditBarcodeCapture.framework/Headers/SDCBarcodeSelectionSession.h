/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeSelectionSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionSession : NSObject

@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *newlySelectedBarcodes;
@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *newlyUnselectedBarcodes;
@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *selectedBarcodes;
@property (nonatomic, readonly) NSInteger frameSequenceId;
@property (nonatomic, readonly) NSInteger lastProcessedFrameId;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)reset;
- (NSInteger)countForBarcode:(nonnull SDCBarcode *)barcode;

@end

NS_ASSUME_NONNULL_END
