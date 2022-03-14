/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>
#import <ScanditCaptureCore/SDCControl.h>
#import <ScanditCaptureCore/SDCBase.h>

@class UIImage;

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(TorchSwitchControl)
SDC_EXPORTED_SYMBOL
@interface SDCTorchSwitchControl : NSObject <SDCControl>

@property (nonatomic, strong, nonnull) UIImage *torchOffImage;
@property (nonatomic, strong, nonnull) UIImage *torchOffPressedImage;
@property (nonatomic, strong, nonnull) UIImage *torchOnImage;
@property (nonatomic, strong, nonnull) UIImage *torchOnPressedImage;

@property (class, nonatomic, nonnull, readonly) UIImage *defaultTorchOffImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultTorchOffPressedImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultTorchOnImage;
@property (class, nonatomic, nonnull, readonly) UIImage *defaultTorchOnPressedImage;

+ (nullable instancetype)torchSwitchControlFromJSONString:(nonnull NSString *)JSONString
                                                    error:(NSError *_Nullable *_Nullable)error;

- (BOOL)updateFromJSONString:(nonnull NSString *)JSONString
                       error:(NSError *_Nullable *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
