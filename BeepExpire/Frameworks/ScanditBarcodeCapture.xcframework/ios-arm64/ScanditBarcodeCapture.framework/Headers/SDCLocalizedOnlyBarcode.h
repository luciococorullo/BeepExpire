/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(LocalizedOnlyBarcode)
SDC_EXPORTED_SYMBOL
@interface SDCLocalizedOnlyBarcode : NSObject

@property (nonatomic, readonly) SDCQuadrilateral location;
@property (nonatomic, readonly) NSUInteger frameId;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
