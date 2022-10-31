TARGET_EXEC := calc

BUILD_DIR := ./build

$(BUILD_DIR)/$(TARGET_EXEC):
	mkdir -p $(dir $@)
	cd build
	cmake ..
	make

.PHONY: clean
clean:
	rm -r $(BUILD_DIR)

-include $(DEPS)
