/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */
#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCDataCaptureOverlay.h>

@class SDCBarcodeCapture;
@class SDCBrush;
@class SDCDataCaptureView;
@protocol SDCViewfinder;

NS_ASSUME_NONNULL_BEGIN

// clang-format off
typedef NS_CLOSED_ENUM(NSUInteger, SDCBarcodeCaptureOverlayStyle) {
    SDCBarcodeCaptureOverlayStyleLegacy NS_SWIFT_NAME(legacy),
    SDCBarcodeCaptureOverlayStyleFrame NS_SWIFT_NAME(frame)
} NS_SWIFT_NAME(BarcodeCaptureOverlayStyle);

SDC_EXTERN NSString *_Nonnull NSStringFromBarcodeCaptureOverlayStyle(SDCBarcodeCaptureOverlayStyle overlayStyle)
    NS_SWIFT_NAME(getter:SDCBarcodeCaptureOverlayStyle.jsonString(self:));
SDC_EXTERN BOOL SDCBarcodeCaptureOverlayStyleFromJSONString(NSString *_Nonnull JSONString,
                                                            SDCBarcodeCaptureOverlayStyle *_Nonnull overlayStyle);
// clang-format on

NS_SWIFT_NAME(BarcodeCaptureOverlay)
SDC_EXPORTED_SYMBOL
@interface SDCBarcodeCaptureOverlay : NSObject <SDCDataCaptureOverlay>

@property (class, nonatomic, nonnull, readonly)
    SDCBrush *defaultBrush DEPRECATED_MSG_ATTRIBUTE("Use defaultBrushForStyle: instead.");
@property (nonatomic, strong, nonnull) SDCBrush *brush;
@property (nonatomic, assign) BOOL shouldShowScanAreaGuides;
@property (nonatomic, strong, nullable) id<SDCViewfinder> viewfinder;
@property (nonatomic, readonly) SDCBarcodeCaptureOverlayStyle style;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture;
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                       forDataCaptureView:(nullable SDCDataCaptureView *)view
    NS_SWIFT_NAME(init(barcodeCapture:view:));

+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                                withStyle:(SDCBarcodeCaptureOverlayStyle)style;
+ (instancetype)overlayWithBarcodeCapture:(nonnull SDCBarcodeCapture *)barcodeCapture
                       forDataCaptureView:(nullable SDCDataCaptureView *)view
                                withStyle:(SDCBarcodeCaptureOverlayStyle)style
    NS_SWIFT_NAME(init(barcodeCapture:view:style:));

+ (nullable instancetype)barcodeCaptureOverlayFromJSONString:(nonnull NSString *)JSONString
                                                        mode:(nonnull SDCBarcodeCapture *)mode
                                                       error:(NSError *_Nullable *_Nullable)error
    NS_SWIFT_NAME(init(jsonString:barcodeCapture:));

+ (nonnull SDCBrush *)defaultBrushForStyle:(SDCBarcodeCaptureOverlayStyle)style
    NS_SWIFT_NAME(defaultBrush(forStyle:));

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

- (void)setValue:(nullable id)value forProperty:(nonnull NSString *)property;

@end

NS_ASSUME_NONNULL_END
