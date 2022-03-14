/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCBase.h>
#import <ScanditCaptureCore/SDCMeasureUnit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol SDCFocusGesture;

NS_SWIFT_NAME(FocusGestureListener)
@protocol SDCFocusGestureListener <NSObject>
- (void)focusGesture:(nonnull id<SDCFocusGesture>)focusGesture
    didTriggerFocusAtPoint:(SDCPointWithUnit)pointWithUnit;
@end

NS_SWIFT_NAME(FocusGesture)
@protocol SDCFocusGesture <NSObject>
@property (nonatomic, nonnull, readonly) NSString *JSONString;
- (void)addListener:(nonnull id<SDCFocusGestureListener>)listener;
- (void)removeListener:(nonnull id<SDCFocusGestureListener>)listener;
- (void)triggerFocus:(SDCPointWithUnit)pointWithUnit;
@end

NS_SWIFT_NAME(TapToFocus)
SDC_EXPORTED_SYMBOL
@interface SDCTapToFocus : NSObject <SDCFocusGesture>

@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (nonnull SDCTapToFocus *)tapToFocus;

@end

NS_ASSUME_NONNULL_END
