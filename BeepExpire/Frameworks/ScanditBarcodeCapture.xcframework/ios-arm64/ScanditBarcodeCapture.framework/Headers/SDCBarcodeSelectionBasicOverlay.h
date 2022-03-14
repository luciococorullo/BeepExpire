/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <UIKit/UIKit.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeSelection;
@class SDCBrush;
@class SDCBarcode;
@class SDCDataCaptureView;
@protocol SDCViewfinder;

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeSelectionBasicOverlayStyle) {
    SDCBarcodeSelectionBasicOverlayStyleFrame NS_SWIFT_NAME(frame),
    SDCBarcodeSelectionBasicOverlayStyleDot NS_SWIFT_NAME(dot)
} NS_SWIFT_NAME(BarcodeSelectionBasicOverlayStyle);

SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeSelectionBasicOverlayStyle(SDCBarcodeSelectionBasicOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeSelectionBasicOverlayStyle.jsonString(self:));
SDC_EXTERN BOOL SDCBarcodeSelectionBasicOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                                   SDCBarcodeSelectionBasicOverlayStyle *_Nonnull overlayStyle);
// clang-format on

NS_SWIFT_NAME(BarcodeSelectionBasicOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeSelectionBasicOverlay : UIView <SDCDataCaptureOverlay>

@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultTrackedBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultTrackedBrushForStyle: instead.");
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultAimedBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultAimedBrushForStyle: instead.");
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultSelectingBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultSelectingBrushForStyle: instead.");
@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultSelectedBrush DEPRECATED_MSG_ATTRIBUTE(
        "Use defaultSelectedBrushForStyle: instead.");

@property (nonatomic, strong, nonnull) SDCBrush *trackedBrush;
@property (nonatomic, strong, nonnull) SDCBrush *aimedBrush;
@property (nonatomic, strong, nonnull) SDCBrush *selectingBrush;
@property (nonatomic, strong, nonnull) SDCBrush *selectedBrush;

@property (nonatomic, assign) BOOL shouldShowHints;
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;
@property (nonatomic, strong, nonnull, readonly) id<SDCViewfinder> viewfinder;

@property (nonatomic, readonly) SDCBarcodeSelectionBasicOverlayStyle style;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;
- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
    NS_SWIFT_NAME(init(barcodeSelection:));
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                                  withStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeSelection:style:));
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                         forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeSelection:view:));
+ (instancetype)overlayWithBarcodeSelection:(nonnull SDCBarcodeSelection *)barcodeSelection
                         forDataCaptureView:(nullable SDCDataCaptureView *)view
                                  withStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeSelection:view:style:));

+ (nonnull SDCBrush *)defaultTrackedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultTrackedBrush(forStyle:));
+ (nonnull SDCBrush *)defaultAimedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultAimedBrush(forStyle:));
+ (nonnull SDCBrush *)defaultSelectingBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultSelectingBrush(forStyle:));
+ (nonnull SDCBrush *)defaultSelectedBrushForStyle:(SDCBarcodeSelectionBasicOverlayStyle)style
    NS_SWIFT_NAME(defaultSelectionBrush(forStyle:));

- (void)clearSelectedBarcodeBrushes;

@end

NS_ASSUME_NONNULL_END
