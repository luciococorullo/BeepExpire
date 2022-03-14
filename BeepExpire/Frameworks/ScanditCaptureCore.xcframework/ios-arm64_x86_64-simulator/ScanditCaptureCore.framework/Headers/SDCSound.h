/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2018- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(Sound)
SDC_EXPORTED_SYMBOL
@interface SDCSound : NSObject

@property (class, nonatomic, readonly) SDCSound *defaultSound;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

- (nullable instancetype)initWithURL:(nonnull NSURL *)url;
- (nullable instancetype)initWithResourceName:(nonnull NSString *)resourceName;

@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
