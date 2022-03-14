/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */
#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeTracking;
@class SDCBrush;
@class SDCTrackedBarcode;
@class SDCBarcodeTrackingBasicOverlay;
@class SDCDataCaptureView;

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeTrackingBasicOverlayStyle) {
    SDCBarcodeTrackingBasicOverlayStyleLegacy NS_SWIFT_NAME(legacy),
    SDCBarcodeTrackingBasicOverlayStyleFrame NS_SWIFT_NAME(frame),
    SDCBarcodeTrackingBasicOverlayStyleDot NS_SWIFT_NAME(dot)
} NS_SWIFT_NAME(BarcodeTrackingBasicOverlayStyle);

SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeTrackingBasicOverlayStyle(SDCBarcodeTrackingBasicOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeTrackingBasicOverlayStyle.jsonString(self:));
SDC_EXTERN BOOL SDCBarcodeTrackingBasicOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                                  SDCBarcodeTrackingBasicOverlayStyle *_Nonnull overlayStyle);
// clang-format on

NS_SWIFT_NAME(BarcodeTrackingBasicOverlayDelegate)
@protocol SDCBarcodeTrackingBasicOverlayDelegate <NSObject>

- (nullable SDCBrush *)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
                            brushForTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

- (void)barcodeTrackingBasicOverlay:(nonnull SDCBarcodeTrackingBasicOverlay *)overlay
               didTapTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

@end

NS_SWIFT_NAME(BarcodeTrackingBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeTrackingBasicOverlay : NSObject <SDCDataCaptureOverlay>

@property (nonatomic, weak, nullable) id<SDCBarcodeTrackingBasicOverlayDelegate> delegate;
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultBrushForStyle: instead.");
@property (nonatomic, strong, nullable)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use brush instead");
@property (nonatomic, strong, nullable) SDCBrush *brush;
@property (nonatomic, readonly) SDCBarcodeTrackingBasicOverlayStyle style;
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking;
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeTracking:view:));
;

+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                                 withStyle:(SDCBarcodeTrackingBasicOverlayStyle)style;
+ (instancetype)overlayWithBarcodeTracking:(nonnull SDCBarcodeTracking *)barcodeTracking
                        forDataCaptureView:(nullable SDCDataCaptureView *)view
                                 withStyle:(SDCBarcodeTrackingBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeTracking:view:style:));

+ (nullable instancetype)barcodeTrackingBasicOverlayFromJSONString:(nonnull NSString *)JSONString
                                                              mode:
                                                                  (nonnull SDCBarcodeTracking *)mode
                                                             error:(NSError **)error
    NS_SWIFT_NAME(init(jsonString:barcodeTracking:));

+ (nonnull SDCBrush *)defaultBrushForStyle:(SDCBarcodeTrackingBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultBrush(forStyle:));

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString error:(NSError **)error;

- (void)setBrush:(nullable SDCBrush *)brush
    forTrackedBarcode:(nonnull SDCTrackedBarcode *)trackedBarcode;

- (void)clearTrackedBarcodeBrushes;

@end

NS_ASSUME_NONNULL_END
