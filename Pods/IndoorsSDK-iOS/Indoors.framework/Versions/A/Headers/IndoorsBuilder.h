//
//  IndoorsBuilder.h
//  indoo.rs 
//
//  Created by Mina Haleem on 08.08.13.
//  Copyright (c) 2013 indoo.rs. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IndoorsDelegate.h"

DEPRECATED_MSG_ATTRIBUTE("Please use [[Indoors alloc] initWithLicenseKey:andServiceDelegate:] instead to init the indoo.rs SDK.")
/**
 @deprecated Deprecated in version 3.3.0
 */
@interface IndoorsBuilder : NSObject

@property (nonatomic, readonly) BOOL built;

@property (nonatomic, weak) id<LoadingBuildingDelegate> loadingBuildingServiceCallBack;
@property (nonatomic, weak) id<IndoorsServiceDelegate> authenticationServiceCallBack;

/**
 @brief Your indoo.rs API key used to access any indoo.rs service.
 */
@property (nonatomic, copy) NSString *apiKey;

/**
  @brief The id of the building to be loaded.
 */
@property (nonatomic) NSInteger buildingId;

/**
 @brief If the builder should enable evaluation mode in the indoo.rs service.
 */
@property (nonatomic, setter=enableEvaluationMode:, getter=isEvaluationModeEnabled) BOOL enableEvaluationMode;

/*!
 @brief Build IndoorsBuilder, this method starts the indoo.rs service and then loads the building.
 You can't change any property or update any values after calling this method.
 */
- (void)build;

@end
