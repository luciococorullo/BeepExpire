/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(EncodingRange)
SDC_EXPORTED_SYMBOL
@interface SDCEncodingRange : NSObject

@property (nonatomic, nonnull, readonly) NSString *ianaName;
@property (nonatomic, readonly) NSUInteger startIndex;
@property (nonatomic, readonly) NSUInteger endIndex;

@property (nonatomic, nonnull, readonly) NSString *JSONString;

@end

NS_ASSUME_NONNULL_END
