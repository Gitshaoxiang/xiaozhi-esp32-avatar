
#include <Avatar.h>
#include <M5Unified.h>

#include <faces/FaceTemplates.hpp>

using namespace m5avatar;

class NeutraFace : public Face {
   public:
    NeutraFace()
        : Face(new Mouth(50, 90, 4, 60), new BoundingRect(148, 163),
               new Eye(8, false), new BoundingRect(93, 90), new Eye(8, true),
               new BoundingRect(96, 230), new Eyeblow(32, 0, false),
               new BoundingRect(67, 96), new Eyeblow(32, 0, true),
               new BoundingRect(72, 230)) {
    }
};

class SleepFace : public Face {
   public:
    SleepFace()
        : Face(new OmegaMouth2(), new BoundingRect(170, 160),
               new EyeSleeping(32, 32, false), new BoundingRect(90, 230),
               new EyeSleeping(32, 32, true), new BoundingRect(90, 90),
               new Eyeblow(32, 0, false), new BoundingRect(67, 96),
               new Eyeblow(32, 0, true), new BoundingRect(72, 230)) {
    }
};

class NervousFace : public Face {
   public:
    NervousFace()
        : Face(new Mouth(50, 90, 4, 60), new BoundingRect(170, 160),
               new EyeNervous(32, 32, false), new BoundingRect(90, 230),
               new EyeNervous(32, 32, true), new BoundingRect(90, 90),
               new Eyeblow(32, 0, false), new BoundingRect(67, 96),
               new Eyeblow(32, 0, true), new BoundingRect(72, 230)) {
    }
};

class LoveFace : public Face {
   public:
    LoveFace()
        : Face(new OmegaMouth2(), new BoundingRect(170, 160),
               new EyeNervous(32, 32, false), new BoundingRect(90, 230),
               new EyeNervous(32, 32, true), new BoundingRect(90, 90),
               new Eyeblow(32, 0, false), new BoundingRect(67, 96),
               new Eyeblow(32, 0, true), new BoundingRect(72, 230)) {
    }
};

class CoolFace : public Face {
   public:
    CoolFace()
        : Face(new OmegaMouth3(), new BoundingRect(170, 160),
               new EyeCool(85, 60, false), new BoundingRect(90, 230),
               new EyeCool(85, 60, true), new BoundingRect(90, 90),
               new Eyeblow(32, 0, false), new BoundingRect(67, 96),
               new Eyeblow(32, 0, true), new BoundingRect(72, 230)) {
    }
};

class StarFace : public Face {
   public:
    StarFace()
        : Face(new OmegaMouth2(), new BoundingRect(170, 160),
               new EyeStar(85, 60, false), new BoundingRect(90, 230),
               new EyeStar(85, 60, true), new BoundingRect(90, 90),
               new Eyeblow(32, 0, false), new BoundingRect(67, 96),
               new Eyeblow(32, 0, true), new BoundingRect(72, 230)) {
    }
};
