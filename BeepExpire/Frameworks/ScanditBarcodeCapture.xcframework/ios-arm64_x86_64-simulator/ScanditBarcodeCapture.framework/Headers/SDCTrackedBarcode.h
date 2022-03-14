/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditBarcodeCapture/SDCSymbology.h>

@class SDCTrackedBarcodeInfo;
@class SDCBarcode;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(TrackedBarcode)
SDC_EXPORTED_SYMBOL
@interface SDCTrackedBarcode : NSObject

@property (nonatomic, readonly) NSTimeInterval deltaTime DEPRECATED_MSG_ATTRIBUTE(
    "Use location instead: it returns a continuously interpolated location");
@property (nonatomic, readonly)
    SDCQuadrilateral predictedLocation DEPRECATED_MSG_ATTRIBUTE("Use location instead");
@property (nonatomic, readonly) SDCQuadrilateral location;
@property (nonatomic, readonly) BOOL shouldAnimateFromPreviousToNextState;
@property (nonatomic, readonly) NSInteger identifier;
@property (nonatomic, nonnull, readonly) SDCBarcode *barcode;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)trackedBarcodeWithTrackedBarcodeInfo:(SDCTrackedBarcodeInfo *)trackedBarcodeInfo;

- (CGPoint)anchorPosition:(SDCAnchor)anchor;

@end

NS_ASSUME_NONNULL_END
