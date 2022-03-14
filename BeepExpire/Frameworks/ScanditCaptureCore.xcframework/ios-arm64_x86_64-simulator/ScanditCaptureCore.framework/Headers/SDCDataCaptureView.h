/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <UIKit/UIView.h>
#import <UIKit/UIApplication.h>

#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>
#import <ScanditCaptureCore/SDCQuadrilateral.h>
#import <ScanditCaptureCore/SDCAnchor.h>
#import <ScanditCaptureCore/SDCControl.h>

@class SDCDataCaptureView;
@class SDCDataCaptureContext;
@protocol SDCDataCaptureOverlay;
@protocol SDCFocusGesture;
@protocol SDCZoomGesture;

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(NSUInteger, SDCLogoStyle) {
    SDCLogoStyleMinimal,
    SDCLogoStyleExtended
} NS_SWIFT_NAME(LogoStyle);

// clang-format off
SDC_EXTERN NSString *_Nonnull NSStringFromLogoStyle(SDCLogoStyle style)
    NS_SWIFT_NAME(getter:SDCLogoStyle.jsonString(self:));
SDC_EXTERN BOOL SDCLogoStyleFromJSONString(NSString *_Nonnull JSONString,
                                           SDCLogoStyle *_Nonnull style);
// clang-format on

NS_SWIFT_NAME(DataCaptureViewListener)
@protocol SDCDataCaptureViewListener <NSObject>

- (void)dataCaptureView:(SDCDataCaptureView *)view
          didChangeSize:(CGSize)size
            orientation:(UIInterfaceOrientation)orientation;

@end

NS_SWIFT_NAME(DataCaptureView)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureView : UIView

@property (nonatomic, strong, nullable) SDCDataCaptureContext *context;
@property (nonatomic, assign) SDCPointWithUnit pointOfInterest;
@property (nonatomic, assign) SDCMarginsWithUnit scanAreaMargins;
@property (nonatomic, assign) SDCAnchor logoAnchor;
@property (nonatomic, assign) SDCPointWithUnit logoOffset;
@property (nonatomic, strong, nullable) id<SDCFocusGesture> focusGesture;
@property (nonatomic, strong, nullable) id<SDCZoomGesture> zoomGesture;
@property (nonatomic, assign) SDCLogoStyle logoStyle;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithFrame:(CGRect)frame;

+ (instancetype)dataCaptureViewForContext:(nullable SDCDataCaptureContext *)context
                                    frame:(CGRect)frame NS_SWIFT_NAME(init(context:frame:));

- (instancetype)initWithCoder:(NSCoder *)decoder NS_UNAVAILABLE;

- (void)addOverlay:(nonnull id<SDCDataCaptureOverlay>)overlay NS_SWIFT_NAME(addOverlay(_:));
- (void)removeOverlay:(nonnull id<SDCDataCaptureOverlay>)overlay NS_SWIFT_NAME(removeOverlay(_:));

- (void)addListener:(nonnull id<SDCDataCaptureViewListener>)listener NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCDataCaptureViewListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (void)addControl:(nonnull id<SDCControl>)control NS_SWIFT_NAME(addControl(_:));
- (void)removeControl:(nonnull id<SDCControl>)control NS_SWIFT_NAME(removeControl(_:));

- (CGPoint)viewPointForFramePoint:(CGPoint)point;
- (SDCQuadrilateral)viewQuadrilateralForFrameQuadrilateral:(SDCQuadrilateral)quadrilateral;

- (void)setValue:(id)value forProperty:(NSString *)property NS_SWIFT_NAME(set(value:forProperty:));

@end

NS_ASSUME_NONNULL_END
