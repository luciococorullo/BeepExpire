/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2020- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_CLOSED_ENUM(NSUInteger, SDCExpiration) {
    SDCExpirationAvailable,
    SDCExpirationPerpetual,
    SDCExpirationNotAvailable
} NS_SWIFT_NAME(Expiration);

NS_SWIFT_NAME(LicenseInfo)
SDC_EXPORTED_SYMBOL
@interface SDCLicenseInfo : NSObject

@property (nonatomic, nullable, readonly) NSDate *date;
@property (nonatomic, readonly) SDCExpiration expiration;
@property (nonatomic, nonnull, readonly) NSString *JSONString;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
