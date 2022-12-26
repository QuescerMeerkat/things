#pragma once

#include "defines.hpp"
#include "zx_buffer.hpp"
#include "zx_device.hpp"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

#include <memory>
#include <vector>

namespace zx {
  enum VoxelType{
    air = 0,
    stone = 1,
    grass = 2
  };
  
  struct Voxel {
    glm::vec3 position{};
    VoxelType type{};

    bool operator==(const Voxel &other) const {
      return type == other.type;
    }
  };
  
  class Chunk {
    public:
      struct Vertex {
        glm::vec3 position{};
        glm::vec3 color{};
        glm::vec3 normal{};

        static std::vector<VkVertexInputBindingDescription> getBindingDescriptions();
        static std::vector<VkVertexInputAttributeDescription> getAttributeDescriptions();

        bool operator==(const Vertex &other) const {
          return position == other.position && color == other.color && normal == other.normal;
        }
      };

      Chunk(ZxDevice &device);
      ~Chunk();

      void bind(VkCommandBuffer commandBuffer);
      void draw(VkCommandBuffer commandBuffer);

      void createVertexBuffers();
      void createIndexBuffers();
      void intializeChunk();
      void createMesh();

      std::vector<Voxel> voxels;

      ZxDevice &zxDevice;

      std::unique_ptr<ZxBuffer> vertexBuffer;
      uint32_t vertexCount;

      bool hasIndexBuffer = false;
      std::unique_ptr<ZxBuffer> indexBuffer;
      uint32_t indexCount;

      std::vector<Vertex> vertices{};
      std::vector<uint32_t> indices{};
  };
}