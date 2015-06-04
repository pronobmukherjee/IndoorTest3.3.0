#import <Foundation/Foundation.h>

/*
 Location inside a building.
 The coordinate origin is the top-left corner in the building.
 For example if x=1500, y=10000, z=2 you are on the second floor and 1,5m
 from the left-most and 10m from the top-most corner in the building map.
 */
@interface IDSCoordinate : NSObject

/**
 @brief Horizontal distance in millimeter from the top-left origin.
 */
@property (nonatomic) NSInteger x;

/**
 @brief Vertical distance in millimeter from the top-left origin.
 */
@property (nonatomic) NSInteger y;

/**
 @brief Floor-ID
 */
@property (nonatomic) NSInteger z;

/**
 @brief Accuracy in mm (radius)
 */
@property (nonatomic) NSInteger accuracy;

- (instancetype)initWithX:(NSInteger)x andY:(NSInteger)y andFloorLevel:(NSInteger)z;
- (instancetype)initWithX:(NSInteger)x Y:(NSInteger)y Z:(NSInteger)z accuracy:(NSInteger)accuracy;
- (NSMutableDictionary *) dictionaryWithBuildingId:(NSInteger)buildingId;
- (BOOL)isEqualToCoordinate:(IDSCoordinate*)coordinate;

@end
