/*
 * This file is part of the Scandit Data Capture SDK
 *
 * Copyright (C) 2017- Scandit AG. All rights reserved.
 */

#import <Foundation/Foundation.h>

#import <ScanditCaptureCore/SDCBase.h>

NS_ASSUME_NONNULL_BEGIN

@class SDCDataCaptureContext;
@class SDCDataCaptureContextSettings;
@class SDCContextStatus;
@class SDCLicenseInfo;
@protocol SDCFrameData;
@protocol SDCFrameSource;
@protocol SDCDataCaptureMode;

NS_SWIFT_NAME(DataCaptureContextListener)
@protocol SDCDataCaptureContextListener <NSObject>

@required

- (void)context:(SDCDataCaptureContext *)context
    didChangeFrameSource:(nullable id<SDCFrameSource>)frameSource;

- (void)context:(SDCDataCaptureContext *)context didAddMode:(id<SDCDataCaptureMode>)mode;

- (void)context:(SDCDataCaptureContext *)context didRemoveMode:(id<SDCDataCaptureMode>)mode;

- (void)context:(SDCDataCaptureContext *)context didChangeStatus:(SDCContextStatus *)contextStatus;

@optional

- (void)didStartObservingContext:(SDCDataCaptureContext *)context;

- (void)didStopObservingContext:(SDCDataCaptureContext *)context;

@end

NS_SWIFT_NAME(DataCaptureContextFrameListener)
@protocol SDCDataCaptureContextFrameListener <NSObject>

@required

- (void)context:(SDCDataCaptureContext *)context willProcessFrame:(id<SDCFrameData>)frame;

- (void)context:(SDCDataCaptureContext *)context didProcessFrame:(id<SDCFrameData>)frame;

@end

NS_SWIFT_NAME(DataCaptureContext)
SDC_EXPORTED_SYMBOL
@interface SDCDataCaptureContext : NSObject

@property (nonatomic, nullable, readonly) id<SDCFrameSource> frameSource;
@property (nonatomic, nullable, readonly)
    NSString *deviceID DEPRECATED_MSG_ATTRIBUTE("Use the class deviceID instead.");
@property (class, nonatomic, nullable, readonly) NSString *deviceID;
@property (nonatomic, nullable, readonly) SDCLicenseInfo *licenseInfo;

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
    NS_SWIFT_NAME(init(licenseKey:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
    NS_SWIFT_NAME(init(licenseKey:externalID:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          deviceName:(nullable NSString *)deviceName
    NS_SWIFT_NAME(init(licenseKey:deviceName:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                       frameworkName:(nullable NSString *)frameworkName
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:frameworkName:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                       frameworkName:(nullable NSString *)frameworkName
                    frameworkVersion:(nullable NSString *)frameworkVersion
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:frameworkName:frameworkVersion:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                            settings:(nullable SDCDataCaptureContextSettings *)settings
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:settings:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                       frameworkName:(nullable NSString *)frameworkName
                            settings:(nullable SDCDataCaptureContextSettings *)settings
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:frameworkName:settings:));

+ (instancetype)contextForLicenseKey:(nonnull NSString *)licenseKey
                          externalID:(nullable NSString *)externalID
                          deviceName:(nullable NSString *)deviceName
                       frameworkName:(nullable NSString *)frameworkName
                    frameworkVersion:(nullable NSString *)frameworkVersion
                            settings:(nullable SDCDataCaptureContextSettings *)settings
    NS_SWIFT_NAME(init(licenseKey:externalID:deviceName:frameworkName:frameworkVersion:settings:));

- (void)addListener:(nonnull id<SDCDataCaptureContextListener>)listener
    NS_SWIFT_NAME(addListener(_:));
- (void)removeListener:(nonnull id<SDCDataCaptureContextListener>)listener
    NS_SWIFT_NAME(removeListener(_:));

- (void)addFrameListener:(nullable id<SDCDataCaptureContextFrameListener>)listener
    NS_SWIFT_NAME(addFrameListener(_:));
- (void)removeFrameListener:(nullable id<SDCDataCaptureContextFrameListener>)listener
    NS_SWIFT_NAME(removeFrameListener(_:));

- (void)setFrameSource:(nullable id<SDCFrameSource>)frameSource
     completionHandler:(nullable void (^)(void))completionHandler;

- (void)addMode:(nonnull id<SDCDataCaptureMode>)mode NS_SWIFT_NAME(addMode(_:));
- (void)removeMode:(nonnull id<SDCDataCaptureMode>)mode NS_SWIFT_NAME(removeMode(_:));

- (void)removeAllModes;

- (void)dispose;

- (void)applySettings:(nonnull SDCDataCaptureContextSettings *)settings
    NS_SWIFT_NAME(applySettings(_:));

@end

NS_ASSUME_NONNULL_END
