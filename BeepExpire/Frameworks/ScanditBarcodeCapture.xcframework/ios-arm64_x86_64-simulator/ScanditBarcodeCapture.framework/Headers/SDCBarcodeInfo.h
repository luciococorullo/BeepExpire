/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeInfo)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeInfo : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithSymbology:(SDCSymbology)symbology data:(nonnull NSString *)data;

- (instancetype)initWithSymbology:(SDCSymbology)symbology
                             data:(nonnull NSString *)data
                         location:(SDCQuadrilateral)location;

@property (nonatomic, readonly) SDCSymbology symbology;
@property (nonatomic, nonnull, readonly) NSString *data;
@property (nonatomic, readonly) SDCQuadrilateral location;

@end

NS_ASSUME_NONNULL_END
