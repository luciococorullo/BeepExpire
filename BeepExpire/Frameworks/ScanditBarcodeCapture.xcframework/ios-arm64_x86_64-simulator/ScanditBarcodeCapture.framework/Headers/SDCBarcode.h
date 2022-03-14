/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCBarcodeInfo;
@class SDCEncodingRange;

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCCompositeFlag) {
    SDCCompositeFlagNone = 0,
    SDCCompositeFlagUnknown = 1,
    SDCCompositeFlagLinked = 2,
    SDCCompositeFlagGS1TypeA = 4,
    SDCCompositeFlagGS1TypeB = 8,
    SDCCompositeFlagGS1TypeC = 16,
} NS_SWIFT_NAME(CompositeFlag);

// clang-format on

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Barcode)
SDC_EXPORTED_SYMBOL
@interface SDCBarcode : NSObject

@property (nonatomic, readonly) SDCSymbology symbology;
@property (nonatomic, nullable, readonly) NSString *data;
@property (nonatomic, nonnull, readonly) NSData *rawData;
@property (nonatomic, nonnull, readonly) NSData *rawDataNoCopy;
@property (nonatomic, nullable, readonly) NSString *addOnData;
@property (nonatomic, nullable, readonly) NSString *compositeData;
@property (nonatomic, nullable, readonly) NSData *compositeRawData;
@property (nonatomic, nonnull, readonly) NSArray<SDCEncodingRange *> *encodingRanges;
@property (nonatomic, readonly) SDCQuadrilateral location;
@property (nonatomic, readonly) BOOL isGS1DataCarrier;
@property (nonatomic, readonly) SDCCompositeFlag compositeFlag;
@property (nonatomic, readonly) BOOL isColorInverted;
@property (nonatomic, readonly) NSInteger symbolCount;
@property (nonatomic, readonly) NSUInteger frameId;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (nonnull instancetype)barcodeWithBarcodeInfo:(SDCBarcodeInfo *)info;

@end

NS_ASSUME_NONNULL_END
