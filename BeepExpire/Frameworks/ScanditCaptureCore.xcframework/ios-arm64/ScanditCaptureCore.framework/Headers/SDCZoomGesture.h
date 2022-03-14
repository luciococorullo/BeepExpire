/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDCZoomGesture;

NS_SWIFT_NAME(ZoomGestureListener)
@protocol SDCZoomGestureListener <NSObject>
- (void)zoomGestureDidZoomIn:(nonnull id<SDCZoomGesture>)zoomGesture;
- (void)zoomGestureDidZoomOut:(nonnull id<SDCZoomGesture>)zoomGesture;
@end

NS_SWIFT_NAME(ZoomGesture)
@protocol SDCZoomGesture <NSObject>
@property (nonatomic, nonnull, readonly) NSString *JSONString;
- (void)addListener:(nonnull id<SDCZoomGestureListener>)listener;
- (void)removeListener:(nonnull id<SDCZoomGestureListener>)listener;
- (void)triggerZoomIn;
- (void)triggerZoomOut;
@end

NS_SWIFT_NAME(SwipeToZoom)
SDC_EXPORTED_SYMBOL
@interface SDCSwipeToZoom : NSObject <SDCZoomGesture>

@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (nonnull SDCSwipeToZoom *)swipeToZoom;

@end

NS_ASSUME_NONNULL_END
