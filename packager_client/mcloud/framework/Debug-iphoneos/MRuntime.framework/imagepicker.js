console.log('loading imagepicker');

var exports = {
	pick: function(callback, pickParam) {
    var fnGallery = this.gallery;
    var fnCamera = this.camera;
    var titles = ['Gallery', 'Camera'];
    mcloud.showActionSheet(titles, function(params){
      if (params == 0) {
        fnGallery(callback, pickParam);
      } else if (params == 1) {
        fnCamera(callback, pickParam);
      }
    });
  },

  gallery: function(callback, pickParam) {
      if (pickParam != null && pickParam != undefined) {
          pickParam.type = 0;
          mcloud.pick(callback, pickParam);
      } else {
          mcloud.pick(callback, {type:0});
      }
  },

  camera: function(callback, pickParam) {
      if (pickParam != null && pickParam != undefined) {
          pickParam.type = 1;
          mcloud.pick(callback, pickParam);
      } else {
          mcloud.pick(callback, {type:1});
      }
  }
};