/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCBarcode;
@class SDCLocalizedOnlyBarcode;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeCaptureSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureSession : NSObject

@property (nonatomic, nonnull, readonly) NSArray<SDCBarcode *> *newlyRecognizedBarcodes;
@property (nonatomic, nonnull, readonly) NSArray<SDCLocalizedOnlyBarcode *> *newlyLocalizedBarcodes;
@property (nonatomic, readonly) NSInteger frameSequenceId;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (void)reset;

@end

NS_ASSUME_NONNULL_END
