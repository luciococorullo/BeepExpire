/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

@class SDCTrackedBarcode;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeTrackingSession)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingSession : NSObject

@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *addedTrackedBarcodes;
@property (nonatomic, nonnull, readonly) NSArray<NSNumber *> *removedTrackedBarcodes;
@property (nonatomic, nonnull, readonly) NSArray<SDCTrackedBarcode *> *updatedTrackedBarcodes;
@property (nonatomic, strong, readonly)
    NSDictionary<NSNumber *, SDCTrackedBarcode *> *trackedBarcodes;
@property (nonatomic, readonly) NSInteger frameSequenceId;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
