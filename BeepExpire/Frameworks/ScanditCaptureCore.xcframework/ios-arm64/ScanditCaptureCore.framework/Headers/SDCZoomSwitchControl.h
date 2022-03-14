/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2021- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ZoomSwitchControl)
SDC_EXPORTED_SYMBOL
@interface SDCZoomSwitchControl : NSObject <SDCControl>

@property (nonatomic, strong, nonnull) UIImage *zoomedOutImage;
@property (nonatomic, strong, nonnull) UIImage *zoomedOutPressedImage;
@property (nonatomic, strong, nonnull) UIImage *zoomedInImage;
@property (nonatomic, strong, nonnull) UIImage *zoomedInPressedImage;

@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedOutImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedOutPressedImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedInImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultZoomedInPressedImage;

+ (nullable instancetype)zoomSwitchControlFromJSONString:(nonnull NSString *)JSONString
                                                   error:(NSError *_Nullable *_Nullable)error;

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
