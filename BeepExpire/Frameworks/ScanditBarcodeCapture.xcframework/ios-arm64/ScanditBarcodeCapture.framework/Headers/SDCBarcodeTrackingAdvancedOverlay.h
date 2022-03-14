/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2019 Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

@class SDCBarcodeTracking;
@class SDCDataCaptureView;
@class SDCTrackedBarcode;
@class SDCBarcodeTrackingAdvancedOverlay;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(BarcodeTrackingAdvancedOverlayDelegate)
@protocol SDCBarcodeTrackingAdvancedOverlayDelegate <NSObject>

- (nullable UIView *)barcodeTrackingAdvancedOverlay:
                         (nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                              viewForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

- (SDCAnchor)barcodeTrackingAdvancedOverlay:(nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                    anchorForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

- (SDCPointWithUnit)barcodeTrackingAdvancedOverlay:
                        (nonnull SDCBarcodeTrackingAdvancedOverlay *)overlay
                           offsetForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

NS_SWIFT_NAME(BarcodeTrackingAdvancedOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingAdvancedOverlay : UIView <SDCDataCaptureOverlay>

@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingAdvancedOverlayDelegate> delegate;
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeTracking:view:));

// clang-format off
+ (nullable instancetype)barcodeTrackingAdvancedOverlayFromJSONString:(nonnull NSString *)JSONString
                                                                 mode:(nonnull SDCBarcodeTracking *)mode
                                                                error:(NSError **)error NS_SWIFT_NAME(init(jsonString:barcodeTracking:));
// clang-format on

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString error:(NSError **)error;

- (void)setView:(nullable UIView *)view
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
- (void)setAnchor:(SDCAnchor)anchor forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
- (void)setOffset:(SDCPointWithUnit)offset
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;
- (void)clearTrackedBarcodeViews;

@end

NS_ASSUME_NONNULL_END
