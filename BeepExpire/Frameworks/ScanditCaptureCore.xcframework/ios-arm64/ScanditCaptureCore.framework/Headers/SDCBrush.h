/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <UIKit/UIView.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Brush)
SDC_EXPORTED_SYMBOL
@interface SDCBrush : NSObject

@property (class, nonatomic, readonly) SDCBrush *transparentBrush;

- (instancetype)init;

- (instancetype)initWithFillColor:(nonnull UIColor *)fillColor
                      strokeColor:(nonnull UIColor *)strokeColor
                      strokeWidth:(CGFloat)strokeWidth NS_DESIGNATED_INITIALIZER;

+ (nullable instancetype)brushFromJSONString:(nonnull NSString *)JSONString

    NS_SWIFT_NAME(init(jsonString:));

@property (nonatomic, nonnull, readonly) UIColor *fillColor;
@property (nonatomic, nonnull, readonly) UIColor *strokeColor;
@property (nonatomic, readonly) CGFloat strokeWidth;

@end

NS_ASSUME_NONNULL_END
