#ifndef VALHALLA_BALDR_TRANSITROUTE_H_
#define VALHALLA_BALDR_TRANSITROUTE_H_

#include <valhalla/baldr/graphconstants.h>

namespace valhalla {
namespace baldr {

/**
 * Information held for each transit route. This is information not required
 * during path generation. Such information is held within the transit
 * schedules and graph edges.
 */
class TransitRoute {
 public:
  // Constructor with arguments
  TransitRoute(const uint32_t routeid, const uint32_t agencyid,
               const char* tl_routeid, const uint32_t short_name_index,
               const uint32_t long_name_index, const uint32_t desc_index);

  /**
   * Get the internal route Id.
   * @return  Returns the internal stop Id.
   */
  uint32_t routeid() const;

  /**
   * Get the internal agency Id for this route.
   * @return  Returns the internal agency Id.
   */
  uint32_t agencyid() const;

  /**
   * Get the TransitLand one stop Id for this route.
   * @return  Returns the TransitLand one-stop Id.
   */
  const char* tl_routeid() const;

  /**
   * Get the text/name index for the short route name.
   * @return  Returns the short name index in the text/name list.
   */
  uint32_t short_name_index() const;

  /**
   * Get the text/name index for the long route name.
   * @return  Returns the short name index in the text/name list.
   */
  uint32_t long_name_index() const;

  /**
   * Get the text/name index for the route description.
   * @return  Returns the description index in the text/name list.
   */
  uint32_t desc_index() const;

  /**
   * operator < - for sorting. Sort by route Id.
   * @param  other  Other transit route to compare to.
   * @return  Returns true if route Id < other route Id.
   */
  bool operator < (const TransitRoute& other) const;

 protected:
  // Internal route Id. Used to lookup/index routes.
  uint32_t routeid_;

  // Internal agency Id this route belongs to.
  uint32_t agencyid_;

  // TransitLand one stop Id for this route.
  char tl_routeid_[kOneStopIdSize];

  // Short route name offset in the text/name list.
  uint32_t short_name_index_;

  // Long route name offset in the text/name list.
  uint32_t long_name_index_;

  // Stop description offset in the text/name list.
  uint32_t desc_index_;
};

}
}

#endif  // VALHALLA_BALDR_TRANSITROUTE_H_
